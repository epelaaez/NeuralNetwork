# Neural Network

Simple neural network coded from scratch with C++.

To compile, run `g++ -o ./execute ./Main.cpp ./Activation.cpp ./Layer.cpp ./Cost.cpp ./NeuralNetwork.cpp --std=c++11` on the terminal. And then `./execute` to run the program defined in `Main.cpp`. 

We use the [Street View House Numbers (SVHN) Dataset](http://ufldl.stanford.edu/housenumbers/) (second format) to test our network. The images from the set have been processed into black and white using the luminosity formula (`grayscale = 0.3 * R + 0.59 * G + 0.11 * B`) for convenience. 

<sub>By Emilio Peláez.</sub>
