#include "raklite/raklite.hpp"

void raklite::console() {
  AllocConsole();
  freopen("CONOUT$", "w", stdout);
}

void raklite::run_command(std::string command) {
  reinterpret_cast<void(__fastcall*)(const char*, bool)>(0x451760)(
      command.data(), false);
}

void raklite::reconnect(std::uint32_t timeout) {
  reinterpret_cast<void (*)()>(0x455960)();
  reinterpret_cast<std::uint32_t(__thiscall*)(std::uint32_t)>(0x457C00)(
      timeout);
  log("[NET] Reconnecting in %d seconds.", timeout / 1000);
}

void raklite::update_sync() { reinterpret_cast<void* (*)()>(0x455210)(); }

void raklite::set_auto_pick(bool state) {
  *reinterpret_cast<bool*>(0x57A0B) = state;
}

void raklite::set_bot_vehicle(std::uint16_t vehicleId, std::uint8_t seatId) {
  *reinterpret_cast<std::uint16_t*>(0x57A157) = vehicleId;
  *reinterpret_cast<std::uint8_t*>(0x57A159) = seatId;
  *reinterpret_cast<std::uint8_t*>(0x578124) = GetTickCount();
  update_sync();
}

void raklite::set_bot_nick(std::string nick) {
  std::strcpy(reinterpret_cast<char*>(0x57A070) + 2, nick.data());
}

void raklite::set_bot_position(raklite::Vector3D position) {
  *reinterpret_cast<raklite::Vector3D*>(0x57A119) = position;
}

void raklite::set_bot_quaternion(Quaternion quat) {
  *reinterpret_cast<Quaternion*>(0x57A125) = quat;
}

void raklite::set_bot_rotation(std::float_t angle) {
  reinterpret_cast<void(__cdecl*)(std::float_t * angle,
                                  Quaternion * Quaternion)>(0x4562E0)(
      &angle, reinterpret_cast<Quaternion*>(0x57A125));
}

void raklite::set_bot_health(std::float_t health) {
  *reinterpret_cast<std::float_t*>(0x57A135) = health;
}

void raklite::set_bot_armor(std::float_t armor) {
  *reinterpret_cast<std::float_t*>(0x57A139) = armor;
}

void raklite::lock_window_text(bool lock) {
  *reinterpret_cast<bool*>(0x4D36A4) = lock;
}

void raklite::set_rate(std::uint8_t rate, std::uint32_t value) {
  reinterpret_cast<std::uint32_t*>(0x57A0C1)[rate] = value;
}

void raklite::spawn() { reinterpret_cast<void (*)()>(0x455BB0)(); }

void raklite::reset_connect_timeout() {
  *reinterpret_cast<std::uint32_t*>(0x4D36A8) = 0;
}

void raklite::coord_start(std::float_t x, std::float_t y, std::float_t z,
                          std::uint32_t delay, std::float_t step,
                          bool off_at_spawn) {
  *reinterpret_cast<raklite::Vector3D*>(0x579E34) = {x, y, z};
  *reinterpret_cast<int*>(0x57A15B) = delay;
  *reinterpret_cast<std::float_t*>(0x57A15F) = step;
  *reinterpret_cast<bool*>(0x57A15A) = off_at_spawn;
  *reinterpret_cast<bool*>(0x4D36A1) = true;
}

void raklite::coord_stop() { *reinterpret_cast<bool*>(0x4D36A1) = false; }

void raklite::set_log_path(std::string path) {
  std::strcpy(reinterpret_cast<char*>(0x53E588), path.data());
}

void raklite::proxy_disconnect() { reinterpret_cast<void (*)()>(0x421870)(); }

void raklite::set_bot_money(std::uint32_t money) {
  *reinterpret_cast<std::uint32_t*>(0x4D36C8) = money;
}

std::string raklite::get_server_name() {
  return std::string(reinterpret_cast<const char*>(0x4D3760));
}

std::uint32_t raklite::get_bot_score() {
  return reinterpret_cast<int(__cdecl*)()>(0x423700)();
}

std::uint32_t raklite::get_bot_ping() {
  return reinterpret_cast<int(__cdecl*)()>(0x423B30)();
}

std::uint8_t raklite::get_bot_interior() {
  return *reinterpret_cast<std::uint8_t*>(0x4D36A3);
}

std::uint32_t raklite::get_bot_skin() {
  return *reinterpret_cast<std::uint32_t*>(0x4D3758);
}

raklite::Vector3D raklite::get_bot_position() {
  return *reinterpret_cast<raklite::Vector3D*>(0x57A119);
}

raklite::Quaternion raklite::get_bot_quaternion() {
  return *reinterpret_cast<raklite::Quaternion*>(0x57A125);
}

std::float_t raklite::get_bot_armor() {
  return *reinterpret_cast<std::float_t*>(0x57A139);
}

std::string raklite::get_network_adapter() {
  return std::string(reinterpret_cast<const char*>(0x57A0F9));
}

bool raklite::is_bot_connected() {
  return reinterpret_cast<bool(__cdecl*)()>(0x423800)();
}

bool raklite::is_player_connected(std::uint16_t playerId) {
  return *reinterpret_cast<bool*>(
      reinterpret_cast<std::uint16_t*>(0x4E88E0)[175 * playerId]);
}

bool raklite::is_coord_active() { return *reinterpret_cast<bool*>(0x4D36A1); }

bool raklite::is_proxy_connected() {
  return reinterpret_cast<bool(__cdecl*)()>(0x4238B0)();
}

bool raklite::is_bot_spawned() { return *reinterpret_cast<bool*>(0x4D36A5); }

std::string raklite::get_bot_nick() {
  return std::string(reinterpret_cast<const char*>(0x57A070) + 2);
}

std::string raklite::get_server_address() {
  return std::string(reinterpret_cast<const char*>(0x579E70));
}

std::string raklite::get_path() {
  return std::string(reinterpret_cast<const char*>(0x57B2E0));
}

std::uint32_t raklite::get_bot_money() {
  return *reinterpret_cast<std::uint32_t*>(0x4D36C8);
}

std::uint16_t raklite::get_bot_id() {
  return *reinterpret_cast<std::uint16_t*>(0x4D36AC);
}

std::uint16_t raklite::get_bot_vehicle() {
  return *reinterpret_cast<std::uint16_t*>(0x57A157);
}

std::float_t raklite::get_bot_health() {
  return *reinterpret_cast<std::float_t*>(0x57A135);
}

RakClientInterface* raklite::get_rakclient_interface() {
  return *reinterpret_cast<RakClientInterface**>(0x4D369C);
}