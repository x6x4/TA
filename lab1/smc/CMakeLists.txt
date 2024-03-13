add_custom_target(smc ALL DEPENDS)
add_custom_command(TARGET smc 
COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR} && make)