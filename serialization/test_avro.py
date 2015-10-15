import avro

from avro.datafile import DataFileReader, DataFileWriter
from avro.io import DatumReader, DatumWriter

schema = avro.schema.parse(open("users.avsc").read())
writer = DataFileWriter(open("users.avro", "w"), DatumWriter(), schema)

writer.append({ "name": "Eduardo", "age": 28 })
writer.append({ "name": "Eddie", "age": 28 })
writer.close()

reader = DataFileReader(open("users.avro"), DatumReader())
for record in reader:
    print record['name'], record['age']

reader.close()

