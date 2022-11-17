# Turing Machine 
  
  > A simple **Turing** Machine made with C/C++ Languages
  
### Dependencies

- [g++ compiler](https://www.guru99.com/c-gcc-install.html) 
  
## Dev Guide
  We need pass like argument to the program files with all information
  > Linux
```bash
  cd
  git https://github.com/Olstertecn11/turing_machine.git
  cd turing_machine
  chmod +x compile.sh
  ./compile.sh
  ./build/main ~/turing_machine/build/file.txt
```

  > **Windows** *( Need Compile again )*
```powershell
  cd
  git clone https://github.com/Olstertecn11/turing_mac.git
  cd turing_machine
  g++ -std=c++17 ./src/main.cpp -o ./build/main
  ./build/main ./build/file.txt 
```

---------------
## File Config for Turing Machine
  - Estados( estado1, estado2, estado3, ... , estadon )
  - Inicial( estado1 )
  - Ha( estadoi )
  - He ( estadoi )
  - Alfabeto( simbolo1, simbolo2, simbolo3., ... )
  - MT (estadoM, símbolo_leido) =  (estadoK, símbolo_escrito, Movimiento) 
  - Movimiento podrá tener únicamente los siguientes valores: 
  - D = Movimiento a la derecha
  - I  = Movimiento a la izquierda
  - N = No se mueve

  ### Example
  ```
  Estado(0, 1, 2, 3)
  Inicial(0)
  Alfabeto(1, 0)
  MT[estadoM, 1] = (estadoK, 0, D)
  MT[estadoM, 0] = (estadoK, 1, D)
  ```

## Collaborators
  ```
    Oliver Jose Tzunun Davila       0901-20-10107
    Luis Alberto Franco Moran       0901-20-23979
    Daniel Antonio Hernández Santos 0901-20-1190
    Otto Adrian Lopez Ventura       0901-20-1069
    
  ```
