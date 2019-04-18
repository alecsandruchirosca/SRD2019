# SRD2019
Surse de Radiatie si Dozimetrie (Master Class 2019)

## Scop
Laboratoarele pentru modelarea transportului radiatiei au scopul de a va familiariza cu utilizarea codurilor generice de calcul. Acest exemplu urmeaza standardele si modalitatile de implementare cu ajutorul framework-ului GEANT (v. 10.05) si simuleaza un detector de GeHP stilizat. Astfel vom ridica spectrul energiei depuse in detector de o sursa de radiatie de <sup>137</sup>Cs cu energia gamma de 661.72keV.
Detectorul simplificat este un cilindru de germaniu cu raza de 3.5 cm si innaltimea de 10 cm implementat cu ajutorul G4Tubs. Acesta este definit ca un volum sensibil iar aplicatia foloseste un fisier root pentru stocarea evenimentelor detectate. Astfel, fiecare interactie a radiatiei cu detectorul va duce la depunerea unei energii  specifice si aceasta este inregistrata in spectru.

Sursa de radiatie este considerata ca fiind punctiforma pentru distantele 10, 30 respectiv 50 de cm pe axa z fata de suprafata detectorului.

## Obiective

Folosind informatiile obtinute, calculati eficacitatea totala a detectorului si eficacitatea de pick a acestuia considerand cazul ideal in care lantul spectrometric functioneaza fara pierderi de semnal.

Folderul data contine fisierele de iesire ce contin spectrele inregistrate folosind macro-ul ROOT:

```
TFile* f("G4APP.root");
TTree* tree;
f.GetObject("102", tree);
tree->SetScanField(0);
.> out.dat
tree->Scan();
.>
.q
```

Folosind aceste date si avand in vedere faptul ca pentru 0cm au fost generate 1E+5 evenimente in sursa, pentru 10cm au fost generate 1E+6 evenimente, pentru 30 de cm 1E+7 evenimente respectiv petru 50 de cm 1E+8 evenimente in sursa puteti calcula eficacitatea relativa, absoluta si de pick pentru sursa noastra de <sup>137</sup>Cs.

## Instalare GEANT4

1. Se instaleaza dependintele minimale:
```
sudo apt update
sudo apt install cmake build-essential qt4-dev-tools libxmu-dev 
    libmotif-dev libexpat1-dev wget git

```
Optional se pot instala si alte pachete
```
sudo apt install libboost-all-dev xfonts-75dpi xfonts-100dpi imagemagick
```

2. Se descarca GEANT4 de la adresa https://geant4.cern.ch
3. Se despacheteaza pachetul GEANT4 intr-un folder. Se intra in folderul unde a fost dezarhivat GEANT4.
4. Se creaza directorul build si se initializeaza compilarea pachetului:
```
mkdir build && cd build
cmake ../ -DGEANT4_BUILD_MULTITHREADED=ON \
    -DGEANT4_USE_QT=ON -DGEANT4_USE_XM=ON -DGEANT4_USE_OPENGL_X11=ON \
    -DGEANT4_USE_RAYTRACER_X11=ON -DGEANT4_INSTALL_DATA=ON -Wno-dev;
make -j`grep -c processor /proc/cpuinfo`
sudo make install
echo `. geant4.sh >> ~/.bashrc`

```

## Descarcarea pachetului din laborator

```
git clone https://github.com/alecsandruchirosca/SRD2019.git
```

cd SRD2019
In acest folder aveti programul din laborator. Pe acesta puteti sa-l compilati manual sau cu ajutorul pachetului Visual Studio Code
```
snap install code --classic
```


### Pentru compilarea manuala

``` 
cd build
cmake ../
make 
./G4APP
```



