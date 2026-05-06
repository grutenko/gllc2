# xxd -i analog

import sys

def bin_to_header(input_file, output_file, var_name="data", string_=True):
    with open(input_file, "rb") as f:
        data = bytearray(f.read())

    if string_:
        data.append(0x00)

    with open(output_file, "w") as f:
        if string_:
          f.write(f"char {var_name}[] = {{\n    ")
        else:
          f.write(f"unsigned char {var_name}[] = {{\n    ")
        for i, b in enumerate(data):
            f.write(f"0x{b:02x}, ")
            if (i + 1) % 12 == 0:
                f.write("\n    ")

        f.write("\n};\n")
        f.write(f"unsigned int {var_name}_len = {len(data)};\n")


def main():
    if len(sys.argv) < 3:
        print("Usage: python xxdi.py input.bin output.h [var_name] [--binary]")
        sys.exit(1)

    inp = sys.argv[1]
    out = sys.argv[2]
    name = "data"
    add_null = True

    for arg in sys.argv[3:]:
        if arg == "--binary":
            add_null = False
        else:
            name = arg

    bin_to_header(inp, out, name, string_=add_null)


if __name__ == "__main__":
    main()