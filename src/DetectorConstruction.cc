#include "DetectorConstruction.hh"
#include "globals.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
//#include "G4SubtractionSolid.hh"
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"
#include "G4ChordFinder.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "SensitiveDetector.hh"
#include "G4SDManager.hh"
#include "G4UserLimits.hh"
#include "Randomize.hh"
#include "G4ThreeVector.hh"
#include "G4GeometryTolerance.hh"
#include "G4GeometryManager.hh"
#include "G4SystemOfUnits.hh"
#include "Geant4/G4Cons.hh"
#include "Geant4/G4Orb.hh"
#include "Geant4/G4Sphere.hh"
#include "Geant4/G4Trd.hh"
#include "Geant4/G4NistManager.hh"
#include "Geant4/G4Polycone.hh"

#include "G4GDMLParser.hh"

DetectorConstruction::DetectorConstruction(AnalysisManager* analysis_manager)
{
  analysis = analysis_manager;
}

DetectorConstruction::~DetectorConstruction(){

}


G4VPhysicalVolume* DetectorConstruction::Construct() 
{
  G4NistManager* nist = G4NistManager::Instance();
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_AIR");
  G4Material* det_mat = nist->FindOrBuildMaterial("G4_Ge");

  G4bool geomDebug = true;
  // rebuild geometry
  G4double detector_radius = 3.5*cm;
  G4double detector_length = 5*cm;

  G4VSolid* worldSolid = new G4Tubs("world", 0.0*mm, 30*cm, 100*cm, 0.0*deg, 360*deg);
  G4LogicalVolume* worldLogical = new G4LogicalVolume(worldSolid, env_mat, "WorldLV");
  G4VPhysicalVolume* worldPhysical = new G4PVPlacement(0, G4ThreeVector(), worldLogical, "WorldPhysical", 0, false, 0, false);
  worldLogical->SetVisAttributes(G4VisAttributes::Invisible);


  G4VSolid* detectorSolid = new G4Tubs("Detector", 0.0*mm, detector_radius, detector_length, 0.0*deg, 360*deg);
  G4LogicalVolume* detectorLogical = new G4LogicalVolume(detectorSolid, det_mat, "DetectorLV");
  new G4PVPlacement(0, G4ThreeVector(), detectorLogical, "DetectorPhysical", worldLogical, false,0,geomDebug);

  G4VisAttributes* detAttr = new G4VisAttributes(G4Color(1.,0.,0.));
  detAttr->SetForceWireframe(true);
  detAttr->SetForceAuxEdgeVisible(true);
  detectorLogical->SetVisAttributes(detAttr);

  return worldPhysical;
}

void DetectorConstruction::ConstructSDandField()
{
   SensitiveDetector* SD = new SensitiveDetector("SD", "DetectorHitsCollection", analysis);
   G4SDManager::GetSDMpointer()->AddNewDetector(SD);
   SetSensitiveDetector("DetectorLV", SD);
}



