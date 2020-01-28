/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"

class ColorDetector : public frc2::SubsystemBase {
 public:
  ColorDetector();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;


  /**
   * Gets the RGB color code.
   */
  void GetColor();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::ColorSensorV3 m_colorSensor{ColorDetectionConstants::i2cPort};
};
