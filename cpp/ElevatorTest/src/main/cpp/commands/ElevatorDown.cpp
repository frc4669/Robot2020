/*----------------------------------------------------------------------------*/
/* Copyright (c) 2020 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorDown.h"

#include "Robot.h"

ElevatorUp::ElevatorUp() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_elevator);
}

// Called just before this Command runs the first time
void ExampleCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ExampleCommand::Execute() 
{
  m_elevator.GoDown();
}

// Make this return true when this Command no longer needs to run execute()
bool ExampleCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void ExampleCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExampleCommand::Interrupted() {}