# Hardware-Implementation-of-Pauli-Y-Gate
## Introduction:
Quantum Gates are rudimentary quantum circuit operating on a small 
number of qubits. Quantum logic gates are reversible and common
quantum gates operate on spaces of one or two qubits.
Quantum gates come in many different varieties. A qubit can be flipped 
from 0 to 1 using single-qubit gates, which also enable the creation of 
superposition states.
Two-qubit gates are a further option. These enable interaction between 
the qubits and can be used to produce quantum entanglement, which is
a condition in which two or more qubits are correlated in a way that is 
not consistent with classical physics.

Due to several of its key characteristics, like reversibility, vast storage 
capacity, and high degree of parallelism, quantum logic systems can 
open up new possibilities for quick and safe computation and data 
processing.

## Pauli-Y Gate:
The Pauli-Y gate is a single-qubit rotation through π radians around the y-axis.The Pauli-Y gate changes the |0⟩ and |1⟩ states as
- ![image](https://user-images.githubusercontent.com/123441538/221490293-a85aa59a-2b41-4bd5-a6ec-4ec6de61ac16.png)
- ![image](https://user-images.githubusercontent.com/123441538/221490410-b69466ef-b7f1-43e5-9950-81a84df3d990.png)

Since Pauli-Y Gate is also a reversible gate, If the output of the Pauli-Y 
Gate acts as an input state for the Pauli-Y Gate, its output resembles the 
previous input given to the gate.
- ![image](https://user-images.githubusercontent.com/123441538/221491360-4c204067-26dc-4159-88f5-f48606c9e841.png)

## Pauli-Y Gate - Qiskit Implementation:
Qiskit is an open-source software development kit that provides tools for 
creating and manipulating quantum programs. To observe the behaviour 
of the Pauli-Y Gate, we mimic the functionality of the gate using the tools 
offered by Qiskit.
We First Import the required libraries:
```python
from qiskit import QuantumCircuit, assemble, Aer
from math import pi,sqrt
from qiskit.visualization import plot_bloch_multivector, plot_histogram
sim = Aer.get_backend('aer_simulator')
```
Create a short circuit and observe its output on the Bloch Sphere:
```python
qc = QuantumCircuit(2)
qc.y(0)
qc.draw()
qc.save_statevector()
qobj = assemble(qc)
state = sim.run(qobj).result().get_statevector()
plot_bloch_multivector(state)
```
Output:

![image](https://user-images.githubusercontent.com/123441538/221494222-d755915e-aadf-40cf-8277-5b55343f9cb7.png)

The application of Y-Gate shows the effect on the Qubits on the Bloch 
Sphere. In this simulation, we can clearly observe a rotation of 180 
degrees about the Y-Axis on the Bloch Sphere.

## Hardware Setup and Plan:
![image](https://user-images.githubusercontent.com/123441538/221495097-24667f8c-9bd1-45e8-92ce-9e77178df7ef.png)

- Initialize the Pauli-Y Gate Matrix by hardcoding the Gate values. 
Since its difficult to add imaginary numbers directly in the program, 
we take the imaginary part as a common factor from the gate 
matrix and later include it in the final part by multiplying the 
common factor back-in.
- Include a 2x1 user input to showcase gate functionality on different inputs.
- Use Xilinx Software Development Kit (XSDK) to program the FPGA and observe the functioning.

Connect the FPGA to the PC and Configure the FPGA:
![image](https://user-images.githubusercontent.com/123441538/221495723-6f3abf65-0c5d-49ac-88d4-889947fad312.png)

Run the program on the FPGA and note the SDK log and Build time:

![image](https://user-images.githubusercontent.com/123441538/221495862-b2d0cc23-ca21-448f-864b-88689cbd18e5.png)

XCST Output:

![image](https://user-images.githubusercontent.com/123441538/221495446-82bec150-6bd4-4cb1-811c-7db8b01b3373.png)


Gate Output:

 ![image](https://user-images.githubusercontent.com/123441538/221495941-04bdf8b0-41cb-4e61-82b4-19ccae3c0d1e.png)











