import numpy as np
import matplotlib.pyplot as plt

class AccessDisplay:

    def  Access(self,FilePath:str):
        try:
            file = open(FilePath,"r")
            QBERArray = []
            for flt in (file.read()).split(','):
                try:
                    QBERArray.append(float(flt)*100)
                except ValueError:
                    continue
            self.QBERArray = QBERArray
        except IndexError:
            print("Off to hell you go")
        self.QBERArray = QBERArray

    def Graph(self):
        threshold = 11
        QBERArray = np.array(self.QBERArray)
        AxisX = np.arange((len(QBERArray)))
        plt.plot(AxisX,QBERArray,label="QuantumBitErrorRate",marker="o")
        plt.axhline(threshold,color="red",linestyle='--',label=f"Threshold={threshold}")
        
        # print(type(QBERArray))

        plt.fill_between(
            AxisX,
            threshold,
            max(QBERArray),
            where=[y > threshold for y in QBERArray],
            color='red',
            alpha = 0.3,
            interpolate=True
        )

        plt.xlabel("")
        plt.ylabel("QBER (%) ")
        plt.title("i'mtiredofgivingnames")
        plt.legend()
        plt.grid(True) # what does this even do
        plt.savefig("/workspace/QBERData/QBERGraph.png",dpi=300,bbox_inches='tight')
        