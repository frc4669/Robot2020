/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include <frc2/command/RunCommand.h>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  
  m_drivetrain.SetDefaultCommand(frc2::RunCommand(
    [this] {
      m_drivetrain.Drive(-f310.getLeftY() * 0.65, -f310.getRightX() * 0.65);
    },
    {&m_drivetrain}
  ));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
