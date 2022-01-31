import numpy as np
import matplotlib.pyplot as plt
import scipy.io.wavfile as wavfile

def makeLoudnessFigure():
    fs, x = wavfile.read("femalecountdown.wav")
    x = x/32768
    win = 100
    energy = np.zeros_like(x)
    energy_c = np.cumsum(x**2)
    for i in range(x.size):
        si = max(0, i-win)
        ei = min(x.size-1, i+win)
        energy[i] = (energy_c[ei]-energy_c[si])/(ei-si+1)
    cutoff = 0.005
    y = x[energy > cutoff]
    plt.figure(figsize=(12, 6))
    plt.subplot(311)
    plt.xlabel("Array Index")
    plt.ylabel("Audio Sample Value")
    plt.title("Original Audio Signal x")
    plt.plot(x)
    plt.xlim([0, x.size-1])
    plt.subplot(312)
    plt.plot(energy)
    plt.xlim([0, x.size-1])
    plt.plot([0, energy.size-1], [cutoff, cutoff], linestyle='--')
    plt.xlabel("Array Index")
    plt.ylabel("Energy")
    plt.subplot(313)
    plt.plot(y)
    plt.xlim([0, x.size-1])
    plt.xlabel("Array Index")
    plt.ylabel("Audio Sample Value")
    plt.title("Filtered Audio y")
    plt.tight_layout()
    plt.savefig("Loudness.png", bbox_inches='tight')



def makeZCSFigure():
    fs, x = wavfile.read("femalecountdown.wav")
    x = x/32768
    win = 2000
    zcs = np.zeros_like(x)
    sign = np.zeros_like(x)
    sign[1::] = 0.5*np.abs(np.sign(x[1::]) - np.sign(x[0:-1]))
    sign_c = np.cumsum(sign)
    for i in range(x.size):
        si = max(0, i-win)
        ei = min(x.size-1, i+win)
        zcs[i] = (sign_c[ei]-sign_c[si])
    cutoff = 150
    y = x[zcs > cutoff]
    plt.figure(figsize=(12, 6))
    plt.subplot(311)
    plt.xlabel("Array Index")
    plt.ylabel("Audio Sample Value")
    plt.title("Original Audio Signal x")
    plt.plot(x)
    plt.xlim([0, x.size-1])
    plt.subplot(312)
    plt.plot(zcs)
    plt.xlim([0, x.size-1])
    plt.plot([0, zcs.size-1], [cutoff, cutoff], linestyle='--')
    plt.xlabel("Array Index")
    plt.ylabel("Zero Crossings")
    plt.subplot(313)
    plt.plot(y)
    plt.xlim([0, x.size-1])
    plt.xlabel("Array Index")
    plt.ylabel("Audio Sample Value")
    plt.title("Filtered Audio y")
    plt.tight_layout()
    plt.savefig("Consonants.png", bbox_inches='tight')

makeLoudnessFigure()
makeZCSFigure()