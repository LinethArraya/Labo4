#PRACTICE 4

Description of the problem.
With a genetic algorithm, we need to create a new generation of chromosomes starting with an initial population of 100 chromosomes, randomly generated. The objective is to find the most powerful chromosome and make the new generation more powerful than the first one.

Description of the solution.
This algorithm it works in the first place for chromosomes that are randomly created, creating a first population, explaining a little bit of the chromosomes, we need to know that they are built by genes, every chromosome has genes that give us information about the chromosome, this information we’re gonna to see like 1’s or 0’s. So in the first place we create a class “Chromosome” that has a gene vector and chromosome fitness, the higher this value, the more opportunities it has to reproduce.
We also have a class “Population” created by 100 chromosomes, were gonna create a new generation of chromosomes,  we will fill it with the following functions, first one were gonna randomly choose two chromosomes in base of the probability that have to be selected to reproduce, were gonna use the function “crossover” with the 0.7 of probability and than were gonna use the function “mutation” with 0.001 of probability, the resulted chromosomes will be formed the new generations (20 times).

Conclusions.
The difficult part of this project was the use of github, this time we used “Visual studio” for the project and the upload and submits complicated us. We decided to do this in a local project and then raise it, we are going to improve our handling of github. The main ideas of the algorithm results easy to understand and solve the problem with that.

Bibliography.
https://www.delftstack.com/es/howto/cpp/cpp-random-number-between-0-and-1/
