/**
 * Copyright 2020, Gerardo Puga
 * garkanoid, patterned Arkanoid clone!
 * */

#pragma once

// garkanoid
#include <garkanoid/GameState.hpp>
#include <garkanoid/interfaces/CommandBase.hpp>
#include <garkanoid/utils/datatypes.hpp>

namespace garkanoid {

class KillAgentCommand : public CommandBase {
public:
  KillAgentCommand(const AgentId &agent_id) : agent_id_{agent_id} {}

  bool execute(const GameStatePtr &world) override {

    auto &agents = world->level_state.agents;
    for (auto it = agents.begin(); it != agents.end(); ++it) {
      if ((*it)->id() == agent_id_) {
        world->level_state.agents.erase(it);
        return true;
      }
    }
    /* the agent id was not found */
    return false;
  };

private:
  const AgentId agent_id_;
};

} // namespace garkanoid
