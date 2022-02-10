convert = {"0":"0000", "1":"0001", "2":"0010", "3":"0011", "4":"0100", "5":"0101", "6":"0110", "7":"0111", "8":"1000", "9":"1001", "A":"1010", "B":"1011", "C":"1100", "D":"1101", "E":"1110", "F":"1111"}
n_bits = 16
reg = "D008"
s = "<table><tr><td><h4>Hex Digits</h4></td>"
for c in reg:
    s += "<td colspan=4><center><h4>{}</h4></center></td>".format(c)
s += "</tr>"
s += "<tr><td><h4>Binary Digits</h4></td>"

bit = n_bits
for c in reg:
    b = convert[c]
    for bi in b:
        if bi == "1":
            s += "<td><b>{}</b></td>".format(bi)
        else:
            s += "<td>{}</td>".format(bi)
s += "</tr><tr><td><h4>Tap Location</h4></td>"
for c in reg:
    b = convert[c]
    for bi in b:
        if bi == "1":
            s += "<td><b>{}</b></td>".format(bit)
        else:
            s += "<td>{}</td>".format(bit)
        bit -= 1
s += "</tr></table>"
print(s)
