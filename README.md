# SRD2019
Surse de Radiatie si Dozimetrie (Master Class 2019)

## Scop
Laboratoarele pentru modelarea transportului radiatiei au scopul de a va familiariza cu utilizarea codurilor generice de calcul. Acest exemplu urmeaza standardele si modalitatile de implementare cu ajutorul framework-ului GEANT (v. 10.05) si simuleaza un detector de GeHP stilizat. Astfel vom ridica spectrul energiei depuse in detector de o sursa de radiatie de <sup>137</sup>Cs cu energia gamma de 661.72keV.
Detectorul simplificat este un cilindru de germaniu cu raza de 3.5 cm si innaltimea de 10 cm implementat cu ajutorul G4Tubs. Acesta este definit ca un volum sensibil iar aplicatia foloseste un fisier root pentru stocarea evenimentelor detectate. Astfel, fiecare interactie a radiatiei cu detectorul va duce la depunerea unei energii  specifice si aceasta este inregistrata in spectru.

Sursa de radiatie este considerata ca fiind punctiforma pentru distantele 10, 30 respectiv 50 de cm pe axa z fata de suprafata detectorului.

## Obiective

Folosind informatiile obtinute, calculati eficacitatea totala a detectorului si eficacitatea de pick a acestuia considerand cazul ideal in care lantul spectrometric functioneaza fara pierderi de semnal.

Folderul data contine fisierele de iesire ce contin spectrele inregistrate folosind macro-ul ROOT:

'''
TFile* f("G4APP.root");
TTree* tree;
tree->SetScanField(0);
.> out.dat
tree->Scan();
.>
.q
'''

Folosind aceste date si avand in vedere faptul ca pentru 0cm au fost generate 1E+5 evenimente in sursa, pentru 10cm au fost generate 1E+6 evenimente, pentru 30 de cm 1E+7 evenimente respectiv petru 50 de cm 1E+8 evenimente in sursa puteti calcula eficacitatea relativa, absoluta si de pick pentru sursa noastra de <sup>137</sup>Cs.

