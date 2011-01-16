/*
**  Xbox360 USB Gamepad Userspace Driver
**  Copyright (C) 2011 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HEADER_XBOXDRV_MODIFIER_CALIBRATION_MODIFIER_HPP
#define HEADER_XBOXDRV_MODIFIER_CALIBRATION_MODIFIER_HPP

#include <vector>

#include "modifier.hpp"

class CalibrationMapping : public Modifier
{
public:
  static CalibrationMapping from_string(const std::string& lhs, const std::string& rhs);

public:
  CalibrationMapping();

  void update(int msec_delta, XboxGenericMsg& msg);

  Modifier::Priority get_priority() const { return Modifier::kCalibrationPriority; };

public:
  XboxAxis m_axis;
  int m_min;
  int m_center;
  int m_max;
};

class CalibrationModifier : public Modifier
{
private:
  std::vector<CalibrationMapping> m_calibration_map;

public:
  CalibrationModifier(const std::vector<CalibrationMapping>& calibration_map);

  void update(int msec_delta, XboxGenericMsg& msg);

  Modifier::Priority get_priority() const { return Modifier::kCalibrationPriority; };

private:
  CalibrationModifier(const CalibrationModifier&);
  CalibrationModifier& operator=(const CalibrationModifier&);
};

#endif

/* EOF */
