/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnElevatorServo.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
TurnElevatorServo::TurnElevatorServo(Elevator * elev, double angle) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({elev});
  elevator = elev;
  targetAngle = angle;
}

// Called when the command is initially scheduled.
void TurnElevatorServo::Initialize() {
  elevator->SetServoAngle(targetAngle);
}
