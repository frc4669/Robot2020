/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"
#include "Constants.h"
#include "Robot.h"

Drivetrain::Drivetrain()
    : m_leftMaster{DriveConstants::kLeftMotor1Port},
      m_leftSlave{DriveConstants::kLeftMotor2Port},
      m_rightMaster{DriveConstants::kRightMotor1Port},
      m_rightSlave{DriveConstants::kRightMotor2Port}
{
    m_leftMaster.Config_kP(0, 8);
    m_leftMaster.Config_kI(0, 0.96);
    m_leftMaster.Config_kD(0, 160);
    m_leftMaster.Config_kF(0, 0.383625);

    m_rightMaster.Config_kP(0, 8);
    m_rightMaster.Config_kI(0, 0.96);
    m_rightMaster.Config_kD(0, 160);
    m_rightMaster.Config_kF(0, 0.383625);

    m_leftSlave.Set(ControlMode::Follower, DriveConstants::kLeftMotor1Port);
    m_rightSlave.Set(ControlMode::Follower, DriveConstants::kRightMotor1Port);

}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}

void Drivetrain::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd*speedMultiplier, rot*speedMultiplier);
}

void Drivetrain::DriveForward(double inches) {
  // m_leftMaster.Set(ControlMode::MotionMagic, inches * DriveConstants::kTicksPerInches);
  // m_rightMaster.Set(ControlMode::MotionMagic, inches * DriveConstants::kTicksPerInches);

  m_rightMaster.Set(ControlMode::PercentOutput, 0.75);
  m_leftMaster.Set(ControlMode::PercentOutput, 0.75);

}

void Drivetrain::RotateRight(double angle) {
  
}

void Drivetrain::ResetEncoders() {
  m_leftMaster.GetSensorCollection().SetQuadraturePosition(0);
  m_rightMaster.GetSensorCollection().SetQuadraturePosition(0);
}

double Drivetrain::GetLeftEncoderDistance() {
  return m_leftMaster.GetSensorCollection().GetQuadraturePosition();
}

double Drivetrain::GetRightEncoderDistance() {
  return m_rightMaster.GetSensorCollection().GetQuadraturePosition();
}

void Drivetrain::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}

units::degree_t Drivetrain::GetHeading() {
  return units::degree_t(std::remainder(m_imu.GetAngle(), 360)) * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

frc::ADIS16448_IMU& Drivetrain::GetIMU()
{
  return m_imu;
}