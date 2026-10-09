## ==OTHERS WAYS OF CONSTRUCTOR MAKING==

![[Pasted image 20261009110704.png]]

![[Pasted image 20261009110722.png]]

![[Pasted image 20261009110911.png]]

## ==WHY IS MEMBER INITIALISATION LIST (MIL) BEST FOR CONSTANT AND REFERENCE VARIABLES??==

![[Pasted image 20261009111905.png]]

![[Pasted image 20261009111925.png]]

![[Pasted image 20261009112003.png]]

![[Pasted image 20261009112031.png]]

![[Pasted image 20261009112045.png]]

![[Pasted image 20261009114546.png]]

![[Pasted image 20261009114607.png]]

![[Pasted image 20261009114627.png]]

## ==WHY CAN'T WE WRITE DIRECT VALUE IN THE CONSTRUCTOR VALUE FOR MIL CONSTRUCTOR??==

![[Pasted image 20261009114928.png]]

![[Pasted image 20261009115056.png]]

![[Pasted image 20261009115115.png]]

![[Pasted image 20261009115231.png]]

![[Pasted image 20261009115248.png]]

![[Pasted image 20261009115315.png]]
## ==FOR LATER!!==

![[Pasted image 20261009110805.png]]

![[Pasted image 20261009110842.png]]

## ==Copy Constructor: Deep Copy vs Shallow Copy & The `&` Pass-by-Reference Trap==

Copy constructor ka signature dhyan se dekho:

![[Pasted image 20260901223247.png]]

### Interview Question 1: Copy constructor me `&` (Pass-by-Reference) mandatory kyu hai?

Agar aap `&` hata doge:

![[Pasted image 20260901223345.png]]

- C++ me pass-by-value karte waqt argument ki **copy** banti hai.
    
- Copy banane ke liye compiler **Copy Constructor** ko call karega.
    
- Wo Copy Constructor dobara pass-by-value dekhega aur fir se Copy Constructor ko call karega.
    
- Isse **Infinite Recursive Loop (Stack Overflow)** ban jayega. Isliye compiler bina `&` ke code compile hi nahi karta.
    

### Interview Question 2: `const` kyu lagate hain?

Taaki source object (`srcObj`) galti se modify na ho jaye (Read-only guarantee).

## ==Stack vs Heap Allocation & The Dynamic Memory Lifecycle==

Video me dikhaya gaya ki memory allocation do tareeqon se hoti hai:

![[Pasted image 20260901223444.png]]

### Destruction of Heap Pointers inside Destructor:

Agar class ke andar dynamic memory allocate hui ho:

![[Pasted image 20260901223508.png]]

## ==Execution Flow & Output Trace (Mental Model)==

Agar ye code chale:

![[Pasted image 20260901223538.png]]

- **Constructor Calling Order:** `A` pehle construct hoga, fir `B`.
    
- **Destructor Calling Order (Stack is LIFO - Last In First Out):** `B` pehle destroy hoga, fir `A`
