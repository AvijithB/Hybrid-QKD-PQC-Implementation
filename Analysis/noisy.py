from Access import AccessDisplay
import sys

FilePath = str(sys.argv[1])
main_noisy = AccessDisplay()
main_noisy.Access(FilePath)
main_noisy.Graph()

