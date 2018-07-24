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
    def check_redist(self):
        redist_library = ['vcruntime140.dll','vcruntime140d.dll', 'MSVCP140.dll']
        found_library = 0
        for list_dll in redist_library:
            if os.path.exists(r"C:\Windows\System32\\" + list_dll):
                found_library +=1
        msg_redist = "VS Redist installed" + '{:.>30}'.format('ok') if found_library == len(redist_library) else " VS Redist 2017 does not install. You must install all required libraries"
        print(msg_redist)

tp = CheckRedist()
tp.check_redist()
os.system("pause")




