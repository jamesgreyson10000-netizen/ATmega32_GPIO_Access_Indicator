# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "C:\\Users\\Hon.Juma\\Desktop\\ATmega32_GPIO_Access_Indicator\\group1\\out\\group1\\default.eep"
  "C:\\Users\\Hon.Juma\\Desktop\\ATmega32_GPIO_Access_Indicator\\group1\\out\\group1\\default.hex"
  "C:\\Users\\Hon.Juma\\Desktop\\ATmega32_GPIO_Access_Indicator\\group1\\out\\group1\\default.lss"
  "C:\\Users\\Hon.Juma\\Desktop\\ATmega32_GPIO_Access_Indicator\\group1\\out\\group1\\default.srec"
  "C:\\Users\\Hon.Juma\\Desktop\\ATmega32_GPIO_Access_Indicator\\group1\\out\\group1\\default.usersignatures"
  )
endif()
