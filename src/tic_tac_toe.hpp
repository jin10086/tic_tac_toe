// Import necessary library
#include <eosio/eosio.hpp>

// Generic eosio library, i.e. print, type, math, etc
using namespace eosio;

CONTRACT tic_tac_toe : public contract
{
public:
    tic_tac_toe(name receiver, name code, datastream<const char *> ds) : contract(receiver, code, ds) {}

    static constexpr name none = "none"_n;
    static constexpr name draw = "draw"_n;

    struct [[eosio::table]] game
    {

        static constexpr uint16_t board_width = 5;
        static constexpr uint16_t board_height = board_width;

        game() : board(board_width * board_height, 0) {}

        name challenger;
        name host;
        name turn;          // = account name of host/ challenger
        name winner = none; // = none/ draw/ name of host/ name of challenger

        std::vector<uint8_t> board;

        // Initialize board with empty cell
        void initialize_board()
        {
            board.assign(board_width * board_height, 0);
        }

        // Reset game
        void reset_game()
        {
            initialize_board();
            turn = host;
            winner = "none"_n;
        }

        auto primary_key() const { return challenger.value; }
        EOSLIB_SERIALIZE(game, (challenger)(host)(turn)(winner)(board))
    };

    typedef eosio::multi_index<"games"_n, game> games;

    ACTION create(const name &challenger, name &host);

    ACTION restart(const name &challenger, const name &host, const name &by);

    ACTION close(const name &challenger, const name &host);

    ACTION move(const name &challenger, const name &host, const name &by, const uint16_t &row, const uint16_t &column);
};