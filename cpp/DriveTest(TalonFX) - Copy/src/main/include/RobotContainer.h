/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/StartEndCommand.h>

#include <ctre/Phoenix.h>

#include "Constants.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Launcher.h"
#include "subsystems/Feeder.h"
#include "subsystems/Intake.h"
#include "F310.h"


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

  F310 f310;

  // The robot's subsystems and commands are defined here...


  // The robot's subsystems
  Drivetrain m_drivetrain;

  Launcher m_launcher;

  Feeder m_feeder;

  Intake m_intake;

  frc2::InstantCommand m_driveHalfSpeed{[this] { m_drivetrain.SetMaxOutput(0.5); },
                                        {}};
  frc2::InstantCommand m_driveFullSpeed{[this] { m_drivetrain.SetMaxOutput(1); },
                                        {}};

  void ConfigureButtonBindings();
};
