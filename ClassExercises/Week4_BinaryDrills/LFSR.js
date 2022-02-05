LFSR_HIGHLIGHT = 1;
LFSR_XOR_1 = 2;
LFSR_XOR_2 = 3;
LFSR_SHIFT = 4;
LFSR_PLACEBIT = 5;

function LSFR(lfsrTable, lfsrStep, lfsrReg, lfsrHeadsTails) {
    this.lfsrTable = lfsrTable;
    this.lfsrStep = lfsrStep;
    this.lfsrReg = lfsrReg;
    this.register = "";
    this.nbits = 0;
    this.taps = [];
    this.state = LFSR_HIGHLIGHT;
    this.lfsrHeadsTails = lfsrHeadsTails;
    this.allbits = [];

    /**
     * Return an array of bits in the taps
     */
    this.extractBits = function() {
        let bits = [];
        for (let i = 0; i < this.taps.length; i++) {
            if (this.register[this.nbits-this.taps[i]] == 0) {
                bits.push(0);
            }
            else {
                bits.push(1);
            }
        }
        return bits;
    }

    this.drawLFSR = function(hlparams) {
        if (hlparams === undefined) {
            hlparams = {};
        }
        if (!('highlightTaps' in hlparams)) {
            hlparams.highlightTaps = false;
        }
        if (!('color' in hlparams)) {
            hlparams.color = 'blue';
        }
        if (!('highlightBit1' in hlparams)) {
            hlparams.highlightBit1 = false;
        }
        let s = "<table border = 1 cellpadding = 5>";
        s += "<tr>";
        for (i = this.nbits; i >= 1; i--) {
            s += "<td><h4>" + i + "</h4></td>";
        }
        s += "</tr>\n<tr>";
        for (let i = 0; i < this.nbits; i++) {
            s += "<td><h2>";
            let highlight = hlparams.highlightTaps && (this.taps.indexOf(this.nbits-i) > -1);
            highlight = highlight | (i == this.nbits - 1 && hlparams.highlightBit1);
            if (highlight) {
                s += "<font color=\"" + hlparams.color + "\">";
            }
            s += this.register[i];
            if (highlight) {
                s += "</font>";
            }
            s += "</h2></td>";
        }
        s += "</tr></table>";
        this.lfsrTable.innerHTML = s;
    }

    this.reset = function(lfsrReg, lfsrTaps, lfsrBits) {
        this.register = hexToBinary(lfsrReg.value);
        this.nbits = parseInt(lfsrBits.value);
        // Make register big enough to accommodate this
        // initial value
        if (this.register.length > this.nbits) {
            this.nbits = this.register.length;
        }
        let taps = lfsrTaps.value.split(",");
        for (let i = 0; i < taps.length; i++) {
            taps[i] = parseInt(taps[i]);
            // Make the register big enough to accommodate
            // the chosen taps
            if (taps[i] > this.nbits) {
                this.nbits = taps[i];
            }
        }
        taps.sort(function(a, b){return b-a});
        this.taps = taps;
        let s = "";
        for (let i = 0; i < taps.length; i++) {
            s += taps[i];
            if (i < taps.length-1) {
                s += ", ";
            }
        }
        lfsrTaps.value = s;
        lfsrBits.value = "" + this.nbits;
        while (this.register.length < this.nbits) {
            this.register = "0" + this.register;
        }
        this.state = LFSR_HIGHLIGHT;
        this.allbits = [];
        this.drawHeadsTails();
        this.drawLFSR({highlightTaps:true, color:"blue"});
    }

    this.drawHeadsTails = function() {
        let s = "";
        for (let i = 0; i < this.allbits.length; i++) {
            s += "<img src = \"";
            if (this.allbits[i] == "1") {
                s += "heads.png";
            }
            else {
                s += "tails.png";
            }
            s += "\">";
            if (i%8 == 7) {
                s += "<BR>";
            }
        }
        this.lfsrHeadsTails.innerHTML = s;
    }

    // Do one step in the lfsr
    this.doStep = function() {
        if (this.state == LFSR_HIGHLIGHT) {
            this.bits = this.extractBits();
            this.state = LFSR_XOR_1;
            this.lfsrStep.innerHTML = "<b>First, we extract the bits from the register at the tap locations</b>";
            this.drawLFSR({highlightTaps:true, color:"red"});
        }
        else if (this.state == LFSR_XOR_1) {
            let s = "<b>Now we perform an XOR on the extracted bits</b><h2>";
            s += "<font color=red>";
            s += this.bits[0];
            s += "</font>";
            for (let i = 1; i < this.bits.length; i++) {
                if (i == 1) {
                    s += "<font color=red>";
                }
                s += " ^ ";
                s += this.bits[i];
                if (i == 1) {
                    s += "</font>";
                }
            }
            if (this.bits.length > 1) {
                this.bits[0] = (this.bits[0] + this.bits[1])%2;
                for (let i = 1; i < this.bits.length-1; i++) {
                    this.bits[i] = this.bits[i+1];
                }
                this.bits.pop();
            }
            this.state = LFSR_XOR_2;
            s += "</h2>";
            this.lfsrStep.innerHTML = s;
        }
        else if (this.state == LFSR_XOR_2) {
            let s = "<b>Now we perform an XOR on the extracted bits</b><h2>";
            for (let i = 0; i < this.bits.length; i++) {
                s += this.bits[i];
                if (i < this.bits.length - 1) {
                    s += " ^ ";
                }
            }
            s += "</h2>";
            this.lfsrStep.innerHTML = s;
            this.state = LFSR_XOR_1;
            if (this.bits.length == 1) {
                this.allbits.push(this.bits[0]);
                this.state = LFSR_SHIFT;
            }
        }
        else if (this.state == LFSR_SHIFT) {
            let s = "<b>Now we shift the array over to the left by one</b>";
            s += "<h2>" + this.bits[0] + "</h2>";
            this.register = this.register.substr(1) + "_";
            this.lfsrStep.innerHTML = s;
            this.drawLFSR();
            this.state = LFSR_PLACEBIT;
        }
        else if (this.state == LFSR_PLACEBIT) {
            let s = "<b>Finally, we place the resulting bit at position 1</b>";
            let bit = "0";
            if (this.bits[0] == 1) {
                bit = "1";
            }
            this.register = this.register.substr(0, this.register.length-1) + bit;
            this.drawLFSR({'higlightBit1':true, 'color':'red'});
            this.lfsrStep.innerHTML = s;
            this.state = LFSR_HIGHLIGHT;
            this.lfsrReg.value = binaryToHex(this.register);
            this.drawHeadsTails();
        }
    }

    this.doTurboStep = function() {
        do {
            this.doStep();
        }
        while (this.state != LFSR_HIGHLIGHT);
    }
} 
