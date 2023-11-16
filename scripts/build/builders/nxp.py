# Copyright (c) 2021 Project CHIP Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
from enum import Enum, auto

from .gn import GnBuilder

class NxpBoard(Enum):
    K32W0 = auto()
    K32W1 = auto()
    RT1060 = auto()
    RT1170 = auto()
    RW612 = auto()

    def GnArgName(self):
        # Example name as it appears in the examples folder.
        if self == NxpBoard.K32W0:
            return 'k32w/k32w0'
        elif self == NxpBoard.K32W1:
            return 'k32w/k32w1'
        elif self == NxpBoard.RT1060:
            return 'rt/rt1060'
        elif self == NxpBoard.RT1170:
            return 'rt/rt1170'
        elif self == NxpBoard.RW612:
            return 'rt/rw612'
        else:
            raise Exception('Unknown board #: %r' % self)

class NxpApp(Enum):
    ALL_CLUSTERS = auto()
    CONTACT = auto()
    LIGHT = auto()
    LIGHT_SWITCH_COMBO = auto()
    LOCK = auto()
    SHELL = auto()

    def ExampleName(self):
        # Example name as it appears in the examples folder.
        if self == NxpApp.ALL_CLUSTERS:
            return 'all-clusters-app'
        elif self == NxpApp.CONTACT:
            return "contact-sensor-app"
        elif self == NxpApp.LIGHT:
            return 'lighting-app'
        elif self == NxpApp.LIGHT_SWITCH_COMBO:
            return 'light-switch-combo-app'
        elif self == NxpApp.LOCK:
            return 'lock-app'
        elif self == NxpApp.SHELL:
            return 'shell'
        else:
            raise Exception('Unknown app type: %r' % self)

    def BuildRoot(self, root, board):
        return os.path.join(root, 'examples', self.ExampleName(), 'nxp', board.GnArgName())

class NxpBuilder(GnBuilder):

    def __init__(self, root, runner, **kwargs):
        self.app = kwargs.pop('app')
        self.board = kwargs.pop('board')
        self.args = kwargs

        super(NxpBuilder, self).__init__(
            root=self.app.BuildRoot(root, self.board),
            runner=runner)

    def GnBuildArgs(self):
        args = list()

        try:
            args.append(
                '%s_sdk_root="%s"' % (self.board.name.lower(), os.environ['NXP_%s_SDK_ROOT' % (self.board.name.upper())])
            )
        except Exception:
            raise Exception('NXP_{%s}_SDK_ROOT not defined' % (self.board.name.upper()))

        if 'release' in self.args and self.args.pop('release') is True:
            args.append('is_debug=false optimize_debug=true')

        if 'rpc_server' in self.args and self.args.pop('rpc_server') is True:
            args.append('import("//with_pw_rpc.gni") treat_warnings_as_errors=false')

        for key, val in self.args.items():
            args.append(f"{key}={val}")

        return args

    def build_outputs(self):
        name = f'chip-{self.board.name.lower()}-{self.app.ExampleName()}'
        return {
            '%s.elf' % name: os.path.join(self.output_dir, name),
            '%s.map' % name: os.path.join(self.output_dir, '%s.map' % name)
        }
