#include "commands/ClimberDownDown.h"
#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ClimberSubsystem.h"

void ClimberDownDown::Initialize() {

}

void ClimberDownDown::Execute() {
  m_climber->ClimberDown();
}

void ClimberDownDown::End(bool interrupted) {
 // m_climber->Stop();
}

bool ClimberDownDown::IsFinished() {
  return false;
}