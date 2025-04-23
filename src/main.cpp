#include <Windows.h>

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>

#include "kthook/kthook.hpp"
#include "raklite/raklite.hpp"

class Main {
 private:
  /* data */
 public:
  Main() {
    raklite::console();
    raklite::log("[%s] Successfully loaded!", "RakPlugin");

    raklite::set_bot_vehicle(123);
    raklite::set_bot_health(88.f);
    printf("VehicleId: %d | Health: %f | ID: %d | Path: %s\n",
           raklite::get_bot_vehicle(), raklite::get_bot_health(),
           raklite::get_bot_id(), raklite::get_path().c_str());

    raklite::set_bot_rotation(180.f);

    raklite::onUpdate += []() {
      static bool initialized = false;
      if (raklite::is_bot_spawned() && !initialized) {
        initialized = true;

        raklite::set_bot_vehicle(15);
        raklite::set_bot_health(50);

        // std::cout << raklite::get_server_address() << std::endl;
        // raklite::set_bot_nick("Nick_Name");
        raklite::set_bot_position({1.f, 3.f, 5.f});
        // raklite::set_bot_quaternion({ 1.f, 1.f, 1.f, 1.f });

        // raklite::run_command("!labels");
        raklite::reconnect();
        raklite::update_sync();

        std::cout << raklite::get_rakclient_interface()->GetAveragePing()
                  << std::endl;
      }
    };

    raklite::onConnect += []() { std::cout << "Connect" << std::endl; };

    raklite::onDisconnect += []() { std::cout << "Disonnect" << std::endl; };

    raklite::onCoordStart += []() { std::cout << "onCoordStart" << std::endl; };

    raklite::onCoordStop += []() { std::cout << "onCoordEnd" << std::endl; };

    // raklite::onSendRPC +=
    //     [](std::uint32_t& id, RakNet::BitStream* bs) { return true; };

    // raklite::onSendRPC +=
    //     [](std::uint32_t& id, RakNet::BitStream* bs) { return true; };
  };

  ~Main() {
    // ...
  };
} main_;