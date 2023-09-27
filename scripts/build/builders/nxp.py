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
    K32W0 = 1
    K32W1 = 2
    RT1060 = 3
    RT1170 = 4
    RW612 = 5

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

    def __init__(self,
                 root,
                 runner,
                 app: NxpApp = NxpApp.LIGHT,
                 board: NxpBoard = NxpBoard.K32W0,
                 release: bool = False,
                 low_power: bool = False,
                 tokenizer: bool = False,
                 disable_ble: bool = False,
                 disable_ota: bool = False,
                 disable_logs: bool = False,
                 se05x: bool = False,
                 tinycrypt: bool = False,
                 crypto_platform: bool = False,
                 openthread_ftd: bool = False,
                 factory_data: bool = False,
                 rotating_device_id: bool = False,
                 smu2_static: bool = False,
                 smu2_dynamic: bool = False,
                 rpc_server: bool = False,
                 matter_cli: bool = False,
                 is_sdk_package: bool = False,
                 no_mcuboot: bool = False):
        super(NxpBuilder, self).__init__(
            root=app.BuildRoot(root, board),
            runner=runner)
        self.code_root = root
        self.app = app
        self.board = board
        self.low_power = low_power
        self.tokenizer = tokenizer
        self.release = release
        self.disable_ble = disable_ble
        self.disable_ota = disable_ota
        self.disable_logs = disable_logs
        self.se05x = se05x
        self.tinycrypt = tinycrypt
        self.crypto_platform = crypto_platform
        self.openthread_ftd = openthread_ftd
        self.factory_data = factory_data
        self.rotating_device_id = rotating_device_id
        self.smu2_static = smu2_static
        self.smu2_dynamic = smu2_dynamic
        self.rpc_server = rpc_server
        self.matter_cli = matter_cli
        self.is_sdk_package = is_sdk_package
        self.no_mcuboot = no_mcuboot

    def GnBuildArgs(self):
        args = []

        try:
            args.append(
                '%s_sdk_root="%s"' % (self.board.name.lower(), os.environ['NXP_%s_SDK_ROOT' % (self.board.name.upper())])
            )
        except Exception:
            raise Exception('NXP_%s_SDK_ROOT not defined' % (self.board.name.upper()))

        if self.low_power:
            args.append('chip_with_low_power=1')
        else:
            args.append('chip_with_low_power=0')

        if self.tokenizer:
            args.append('chip_pw_tokenizer_logging=true')

        if self.release:
            args.append('is_debug=false optimize_debug=true')

        if self.disable_ble:
            args.append('chip_enable_ble=false')

        if self.disable_ota:
            args.append('chip_enable_ota_requestor=false')

        if self.disable_logs:
            args.append('chip_logging=false')

        if self.se05x:
            args.append('chip_with_se05x=true')

        if self.tinycrypt:
            args.append('chip_crypto=\"platform\" chip_crypto_flavor=\"tinycrypt\"')

        if self.crypto_platform:
            args.append('chip_crypto=\"platform\"')

        if self.openthread_ftd:
            args.append('chip_openthread_ftd=true')

        if self.factory_data:
            args.append('chip_with_factory_data=1')

        if self.rotating_device_id:
            args.append('chip_enable_rotating_device_id=1 chip_enable_additional_data_advertising=1')

        if self.smu2_static:
            args.append('use_smu2_static=true')

        if self.smu2_dynamic:
            args.append('use_smu2_dynamic=true')

        if self.rpc_server:
            args.append('import("//with_pw_rpc.gni") treat_warnings_as_errors=false')

        if self.matter_cli:
            args.append('chip_enable_matter_cli=true')

        if self.is_sdk_package:
            args.append('is_sdk_package=true')
        else:
            args.append('is_sdk_internal=true')

        if self.no_mcuboot:
            args.append('no_mcuboot=false')

        return args

    def build_outputs(self):
        return {
            '%s.elf' % name: os.path.join(self.output_dir, name),
            '%s.map' % name: os.path.join(self.output_dir, '%s.map' % name)
        }
