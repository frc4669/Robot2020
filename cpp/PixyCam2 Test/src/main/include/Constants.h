/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
  constexpr int kLeftMotor1Port = 14;
  constexpr int kLeftMotor2Port = 11;
  constexpr int kRightMotor1Port = 12;
  constexpr int kRightMotor2Port = 13;

  // These are example values only - DO NOT USE THESE FOR YOUR OWN ROBOT!
  // These characterization values MUST be determined either experimentally or
  // theoretically for *your* robot's drive. The RobotPy Characterization
  // Toolsuite provides a convenient tool for obtaining these values for your
  // robot.
  constexpr auto ks = 1_V;
  constexpr auto kv = 0.8_V * 1_s / 1_m;
  constexpr auto ka = 0.15_V * 1_s * 1_s / 1_m;

  constexpr double kp = 1;

  constexpr auto kMaxSpeed = 3_mps;
  constexpr auto kMaxAcceleration = 3_mps_sq;

  constexpr double kWheelDiameter = 6;
  constexpr double kPi = 3.14159265359;
  constexpr double kTicksPerRotation = 4096; // replace with actual number
  constexpr double kWheelCircumference = kWheelDiameter * kPi;
  constexpr double kFirstStageGearRatio = 0.25; // replace with actual number
  constexpr double kSecondStageGearRatio = 0.25; //replace with actual number
  constexpr double kThirdStageGearRatio = 0.25; //replace with actual number
  constexpr double kInchesPerTicks = kWheelCircumference / (kTicksPerRotation * kFirstStageGearRatio * kSecondStageGearRatio * kThirdStageGearRatio);
  constexpr double kTicksPerInches = kTicksPerRotation * kFirstStageGearRatio * kSecondStageGearRatio * kThirdStageGearRatio / kWheelCircumference;
  constexpr auto kTurnTolerance = 5_deg; // replace with actual number
  constexpr auto kTurnRateTolerance = 10_deg_per_s; // replace with actual number
  constexpr bool kGyroReversed = false; //replace with actual number

} 