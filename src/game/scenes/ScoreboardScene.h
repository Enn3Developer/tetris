#ifndef SCOREBOARDSCENE_H
#define SCOREBOARDSCENE_H
#include "Scoreboard.h"
#include "../../engine/Scene.h"
#include "../../engine/components/Button.h"
#include "../../engine/components/Label.h"
 using namespace std;

class ScoreboardScene final : public Scene, public Scoreboard
{
    Label title;
    Label score;
    Button exit;
public:
    ScoreboardScene();
    ~ScoreboardScene() override;
};

void exitButton(RunContext* ctx);
#endif //SCOREBOARDSCENE_H
