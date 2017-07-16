#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game();
        void input();
        void update();
        void render();
        virtual ~Game();

    protected:

    private:
        Game(const Game& other) { }
        void operator=(const Game& other) { }
};

#endif // GAME_H
