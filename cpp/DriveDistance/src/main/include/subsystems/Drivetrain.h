/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "ctre/Phoenix.h"
#include <adi/ADIS16470_IMU.h>

class Drivetrain : public frc2::SubsystemBase
{
public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  /**
   * Drives the robot using arcade controls.
   *
   * @param fwd the commanded forward movement
   * @param rot the commanded rotation
   */
  void ArcadeDrive(double fwd, double rot);

 /**
   * Drives the robot forward using Motion Magic.
   *
   * @param inches distance in inches to drive forward
   */
  void DriveForward(double inches);

/**
   * Rotates the robot in place using Motion Magic.
   *
   * @param angle angle in degrees to rotate clockwise
   */
  void RotateRight(double angle);

  /**
   * Resets the drive encoders to currently read a position of 0.
   */
  void ResetEncoders();

  /**
   * Gets the distance of the left encoder.
   *
   * @return the average of the TWO encoder readings
   */
  double GetLeftEncoderDistance();

  /**
   * Gets the distance of the right encoder.
   *
   * @return the average of the TWO encoder readings
   */
  double GetRightEncoderDistance();

  /**
   * Sets the max output of the drive.  Useful for scaling the drive to drive
   * more slowly.
   *
   * @param maxOutput the maximum output to which the drive will be constrained
   * i.e. multiplies percent output by maxOutput
   */
  void SetMaxOutput(double maxOutput);

  frc::ADIS16470_IMU GetIMU();

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // The motor controllers
  WPI_TalonFX m_leftMaster;
  WPI_TalonFX m_leftSlave;
  WPI_TalonFX m_rightMaster;
  WPI_TalonFX m_rightSlave;

  // The robot's IMU
  frc::ADIS16470_IMU m_imu{};
  // The robot's drive
  frc::DifferentialDrive m_drive{m_leftMaster, m_rightMaster};
};
