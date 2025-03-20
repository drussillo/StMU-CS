/* C program by Dave Russillo. Made on 03/20/2025 for CS1311. Graph representing a flashlight */
#include <stdio.h>
#include <string.h>


struct Gizmo {
  char name[50];
  struct Gizmo *part1;
  struct Gizmo *part2;
  struct Gizmo *part3;
  struct Gizmo *contains1;
  struct Gizmo *contains2;
};
struct Gizmo flashlight, flashlight_case, battery, light, flashlight_switch;


void create_flashlight(void) {
  strcpy(flashlight.name, "flashlight");
  strcpy(flashlight_case.name, "case");
  strcpy(battery.name, "battery");
  strcpy(light.name, "light");
  strcpy(flashlight_switch.name, "switch");

  flashlight.part1 = &flashlight_case;
  flashlight.part2 = &battery;
  flashlight.part3 = &light;
  flashlight.contains1 = NULL;
  flashlight.contains2 = NULL;

  flashlight_case.part1 = &flashlight_switch;
  flashlight_case.part2 = NULL;
  flashlight_case.part3 = NULL;
  flashlight_case.contains1 = &battery;
  flashlight_case.contains2 = &light;

  battery.part1 = NULL;
  battery.part2 = NULL;
  battery.part3 = NULL;
  battery.contains1 = NULL;
  battery.contains2 = NULL;

  light.part1 = NULL;
  light.part2 = NULL;
  light.part3 = NULL;
  light.contains1 = NULL;
  light.contains2 = NULL;

  flashlight_switch.part1 = NULL;
  flashlight_switch.part2 = NULL;
  flashlight_switch.part3 = NULL;
  flashlight_switch.contains1 = NULL;
  flashlight_switch.contains2 = NULL;
}


void print_gizmo(struct Gizmo *object) {
  printf("A part is %s.\n", object->name);
}


int main(void) {
  printf("This program prints out connections in a flashlight.\n");
  create_flashlight();
  print_gizmo(&flashlight);

  return 0;
}
