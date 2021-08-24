import sys

def read_sauberes_text_file(filename):
    data = []
    f = open(filename)
    for line in f:
        fields = line.split('|')

        material = int(fields[1].strip())
        werk = fields[2].strip()
        lort = fields[3].strip()
        b = fields[4].strip()
        if len(b) == 0:
            b = None
        charge = fields[5].strip()
        if len(charge) == 0:
            charge = None
        s = fields[6].strip()
        if len(s) == 0:
            s = None
        sonderbestandsnummer = fields[7].strip()
        if len(sonderbestandsnummer) == 0:
            sonderbestandsnummer = None
        materialkurztext = fields[8].strip()
        typ = fields[9].strip()
        lagerplatz = fields[10].strip()
        verfueg_bestand = fields[11].strip()
        bme = fields[12].strip()
        we_datum = fields[13].strip()

        record = (
            material,
            werk,
            lort,
            b,
            charge,
            s,
            sonderbestandsnummer,
            materialkurztext,
            typ,
            lagerplatz,
            verfueg_bestand,
            bme,
            we_datum,
        )
        
        data.append(record)

    return data

records = read_sauberes_text_file(sys.argv[1])
for r in records:
    print(
        'Material:', r[0],
        ', Werk:', r[1],
        ', LOrt:', r[2],
        ', B:', r[3],
        ', Charge:', r[4],
        ', S:', r[5],
        ', Sonderbestandsnummer:', r[6],
        ', Materialkurztext:', r[7],
        ', Typ:', r[8],
        ', Lagerplatz:', r[9],
        ', Verfüg.Bestand:', r[10],
        ', BME:', r[11],
        ', WE-Datum:', r[12],
    )
