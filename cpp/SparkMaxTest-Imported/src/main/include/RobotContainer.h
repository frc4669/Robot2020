/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#pragma once
 
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h> 
#include "Constants.h"
#include "subsystems/Launcher.h"
 
namespace ac = AutoConstants;
 
/**
* This class is where the bulk of the robot should be declared.  Since
* Command-based is a "declarative" paradigm, very little robot logic should
* actually be handled in the {@link Robot} periodic methods (other than the
* scheduler calls).  Instead, the structure of the robot (including subsystems,
* commands, and button mappings) should be declared here.
*/
class RobotContainer {
public:
  RobotContainer();
 
  frc2::Command* GetAutonomousCommand();
 
private:
  // The driver's controller
  frc::XboxController m_driverController{OIConstants::kDriverControllerPort};
 
  // The robot's subsystems and commands are defined here...
 
  // The robot's subsystems
  DriveSubsystem m_drive;
  ArmSubsystem m_arm;
 
  Launcher m_launcher;
 
  // The chooser for the autonomous routines
 
  void ConfigureButtonBindings();
};