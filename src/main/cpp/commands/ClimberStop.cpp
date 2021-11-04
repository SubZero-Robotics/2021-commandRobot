#include "commands/ClimberStop.h"
#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ClimberSubsystem.h"

void ClimberStop::Initialize() {

}

void ClimberStop::Execute() {
  m_climber->ClimberStop();
}

void ClimberStop::End(bool interrupted) {
 // m_climber->Stop();
}

bool ClimberStop::IsFinished() {
  return false;
}