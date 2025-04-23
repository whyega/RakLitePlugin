#ifndef RAKLITE_HPP
#define RAKLITE_HPP

#include <Windows.h>

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "RakNet/BitStream.h"
#include "RakNet/RakClientInterface.h"
#include "kthook/kthook.hpp"

namespace raklite {
template <typename T, typename U>
struct Event {
  T hook;
  std::vector<std::function<U>> events;

  Event(std::uintptr_t address) {
    hook.set_dest(address);
    hook.set_cb([this](const T& hook, auto&&... args) {
      for (auto handler : events) {
        handler();
      }
    });
    hook.install();
  }

  Event& operator+=(std::function<U> func) {
    this->events.push_back(func);
    return *this;
  }
};

struct Vector3D {
  std::float_t x;
  std::float_t y;
  std::float_t z;
};

struct Quaternion {
  std::float_t w;
  std::float_t x;
  std::float_t y;
  std::float_t z;
};

inline Event<kthook::kthook_naked, void()> onUpdate{0x454DD4};
inline Event<kthook::kthook_naked, void()> onRequestConnect{0x454D56};
inline Event<kthook::kthook_naked, void()> onConnect{0x4580CF};
inline Event<kthook::kthook_naked, void()> onDisconnect{0x4580AF};
inline Event<kthook::kthook_naked, void()> onProxyConnect{0x45BBD1};
inline Event<kthook::kthook_naked, void()> onProxyDisconnect{0x45BC3F};
inline Event<kthook::kthook_naked, void()> onProxyError{0x45BA09};
inline Event<kthook::kthook_naked, void()> onCoordStart{0x41FC73};
inline Event<kthook::kthook_naked, void()> onCoordStop{0x454CA8};

// using onSendRPC_t = bool(__thiscall*)(int* uniqueID, const char *data,
// unsigned int bitLength, PacketPriority priority, PacketReliability
// reliability, char orderingChannel, bool shiftTimestamp, NetworkID networkID,
// RakNet::BitStream *replyFromTarget); inline
// Event<kthook::kthook_simple<onSendRPC_t2>, bool(int* uniqueID, const char
// *data, unsigned int bitLength, PacketPriority priority, PacketReliability
// reliability, char orderingChannel, bool shiftTimestamp, NetworkID networkID,
// RakNet::BitStream *replyFromTarget)> onSendRPC { 0x4045E0 };

template <typename T>
void log(const char* message, T format) {
  reinterpret_cast<void*(__cdecl*)(const char*, T)>(0x454F80)(message, format);
};

void console();

void set_bot_nick(std::string nick);
void set_bot_position(Vector3D position);
void set_bot_quaternion(Quaternion quat);
void set_bot_rotation(std::float_t angle);  // TODO
void set_bot_health(std::float_t health);
void set_bot_armor(std::float_t armor);
void lock_window_text(bool lock);
void set_rate(std::uint8_t rate, std::uint32_t value);
void run_command(std::string command);
void reconnect(
    std::uint32_t timeout = *reinterpret_cast<std::uint32_t*>(0x57A0C9));
void spawn();
void update_sync();
void reset_connect_timeout();
void set_bot_vehicle(std::uint16_t vehicleId, std::uint8_t seatId = 0);
void coord_start(std::float_t x, std::float_t y, std::float_t z,
                 std::uint32_t delay, std::float_t step,
                 bool off_at_spawn);  // TODO
void coord_stop();
void set_log_path(std::string path);
void set_auto_pick(bool state);
void proxy_connect(std::string address, std::string username,
                   std::string password);  // TODO
void proxy_disconnect();
void set_bot_money(std::uint32_t money);

std::uint16_t get_bot_id();
std::string get_server_address();
std::string get_server_name();
std::string get_bot_nick();
std::uint32_t get_bot_score();
std::uint32_t get_bot_ping();
bool is_bot_spawned();
std::uint8_t get_bot_interior();
std::uint32_t get_bot_skin();
Vector3D get_bot_position();
Quaternion get_bot_quaternion();
std::float_t get_bot_rotation();  // TODO
std::float_t get_bot_health();
std::float_t get_bot_armor();
std::string get_network_adapter();
bool is_bot_connected();
std::uint16_t get_bot_vehicle();
bool is_coord_active();
std::string get_path();
bool is_proxy_connected();
std::uint32_t get_bot_money();
std::uint32_t get_player_count(bool stream = false);  // TODO
bool is_player_connected(std::uint16_t playerId);

RakClientInterface* get_rakclient_interface();
}  // namespace raklite

#endif  // RAKLITE_HPP
