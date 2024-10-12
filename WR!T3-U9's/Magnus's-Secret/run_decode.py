from decode import decode
def main():

    # pgn_string = input("Enter the PGN string :")
    
    pgn_string = '''1. h3 f6 2. f3 h5 3. g3 Rh6 4. g4 g6 5. h4 a6 6. Kf2 c6 7. Ke1 Bg7 8. Kf2 Ra7 9. Rh2 f5 10. Ke3 Qb6+ 11. Kf4 Rh8 12. Rh1 Nh6 13. Rh3 d6 14. Rh2 Rh7 15. Nh3 Qxb2 16. gxf5 Rh8 17. Nf2 Rg8'''

    output_file_path = "flag.txt" 
    
    decode(pgn_string, output_file_path)

if __name__ == "__main__":
    main()

