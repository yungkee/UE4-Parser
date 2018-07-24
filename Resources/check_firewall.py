import os
import platform
import subprocess
import sys
import os
from glob import glob


class Executor:
    @staticmethod
    def run(commands = [], *args):
        result = []
        child = subprocess.Popen(commands, stdout=subprocess.PIPE)
        while child.poll() is None:
            output_line = child.stdout.readline()
            output_line = output_line.decode("utf-8")[:-1]
            if (output_line):
                result.append(output_line)
        code = child.returncode
        if (code):
            os.sys.exit(code)
        return result

class CheckRedist:
    def check_firewall(self):
        firewall_report = Executor.run(["netsh","advfirewall","show","allprofiles"])

        enabled_states_count = 0
        for line in firewall_report:
            is_state = line[0:5] == "State"
            if is_state:
                if line[38:40] == "ON":
                    enabled_states_count +=1
        msg_firewall = "Firewall: " + "Enable" + '{:.>30}'.format('ok') if enabled_states_count > 0 else "Disable"
        print(msg_firewall)

tp = CheckRedist()
tp.check_firewall()
os.system("pause")




