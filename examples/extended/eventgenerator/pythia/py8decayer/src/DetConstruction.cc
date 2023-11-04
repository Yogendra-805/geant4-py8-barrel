//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file eventgenerator/pythia/pythia8decayer/src/DetConstruction.cc
/// \brief Implementation of the DetConstruction class
///
/// \author J. Yarba; FNAL

#include "DetConstruction.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PhysicalConstants.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetConstruction::Construct()
{

   // Define materials via NIST manager
  
   auto worldMaterial = 
      G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"); 
   auto detMaterial   = 
      G4NistManager::Instance()->FindOrBuildMaterial("G4_C"); 

   // World volume
  double xWorld = 0.8*CLHEP::m;
  double yWorld = 0.8*CLHEP::m;
  double zWorld = 0.8*CLHEP::m;
   //G4ThreeVector worldSize( 200.*CLHEP::cm, 200.*CLHEP::cm, 200.*CLHEP::cm );
  
   G4VSolid* solidWorld = new G4Box("solidWorld",xWorld,yWorld,zWorld);
    
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, worldMaterial,"logicWorld");

    physWorld = new G4PVPlacement(0,G4ThreeVector(0,0,0),logicWorld,"physWorld",0,false,0,true);


  G4double x = 0.5*CLHEP::cm;
  G4double y = 1*CLHEP::cm;
  G4double z = 1*CLHEP::cm;

  G4VSolid* sDet = new G4Box("solidScintillator",x, y,z);
  G4LogicalVolume* lDet = new G4LogicalVolume(sDet,detMaterial,"logicalScintillator");
  //G4LogicalSkinSurface *skin = new G4LogicalSkinSurface("skin", logicWorld, mirrorSurface);
 
  //fScoringVolume = logicScintillator;
  
  
  
  // // First ring of our detector.
  G4double theta1 = 360/(twopi*7);
  for(G4int c=0;c<60;c++){  // cell in z-direction
    
    for (G4int p=0;p<twopi*7;p++){ // cell on x-y plane.

      G4Rotate3D rotZ(p*theta1*CLHEP::deg,G4ThreeVector(0,0,1));
      G4Translate3D transXScint(G4ThreeVector(1./tan(theta1/2*CLHEP::deg)*CLHEP::cm +1.0*CLHEP::cm,0*CLHEP::cm,-57.5*CLHEP::cm+c*2*CLHEP::cm));  // Z-no change

      G4Transform3D transformScint = (rotZ)*(transXScint);


      fDet = new G4PVPlacement(transformScint,lDet,"physScintillator",logicWorld,false,0,false);
    }
    }

  // Second ring of our detector.
  G4double theta2 = 360/(twopi*14);
  for(G4int c=0;c<60;c++){  // cell in z-direction
    
    for (G4int p=0;p<twopi*14;p++){ // cell on x-y plane.

      G4Rotate3D rotZ(p*theta2*CLHEP::deg,G4ThreeVector(0,0,1));
      G4Translate3D transXScint(G4ThreeVector(1./tan(theta2/2*CLHEP::deg)*CLHEP::cm+1.*CLHEP::cm,0*CLHEP::cm,-57.5*CLHEP::cm+c*2*CLHEP::cm));
  
      G4Transform3D transformScint = (rotZ)*(transXScint);
 
      fDet = new G4PVPlacement(transformScint,lDet,"physScintillator",logicWorld,false,0,false);
    }
    }
  // Third ring of our detector.
  G4double theta3 = 360/(twopi*21);
  for(G4int c=0;c<60;c++){  // cell in z-direction
    
    for (G4int p=0;p<twopi*21;p++){ // cell on x-y plane.

      G4Rotate3D rotZ(p*theta3*CLHEP::deg,G4ThreeVector(0,0,1));
      G4Translate3D transXScint(G4ThreeVector(1./tan(theta3/2*CLHEP::deg)*CLHEP::cm+1.*CLHEP::cm,0*CLHEP::cm,-57.5*CLHEP::cm+c*2*CLHEP::cm));
  
      G4Transform3D transformScint = (rotZ)*(transXScint);
 
      fDet = new G4PVPlacement(transformScint,lDet,"physScintillator",logicWorld,false,0,false);
    }
    }
 
  return physWorld;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

