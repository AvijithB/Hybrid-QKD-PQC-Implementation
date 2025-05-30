from Access import AccessDisplay
import sys

FilePath = str(sys.argv[1])
main_clean = AccessDisplay()
main_clean.Access(FilePath)
main_clean.Graph()