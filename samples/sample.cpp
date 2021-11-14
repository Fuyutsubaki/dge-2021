
#include<cinttypes>
#include<algorithm>
using i32 = std::int32_t;

extern "C"
{

    int pt = 0;

    // player_hand_val プレイヤーの現在の所持金
    // 戻り値 BET額
    i32 bet(i32 money)
    {
        if (pt > 6)
            return money / 4;

        return 1;
    }

    // player_hand_val プレイヤーの現在のハンドの合計値
    // dealer_hand_val ディーラーの現在のハンドの合計値
    // enable_double_down double down可能か？
    // 戻り値=0 Hitする
    // 戻り値=1 Stayする
    // 戻り値=1 Double downする
    i32 action(i32 player_hand_val, i32 dealer_hand_val, i32 enable_double_down)
    {
        if (12 <= player_hand_val && player_hand_val <= 16 && dealer_hand_val <= 6 || player_hand_val >= 17)
        {
            return 1;
        }

        return 0;
    }

    // type=0 プレイヤーが $valのカードを引いた
    // type=1 ディーラーが $valのカードを引いた
    // type=2 リシャッフルされた
    void event(i32 type, i32 val)
    {
        if (type == 0 || type == 1)
            if (2 <= val && val <= 6)
                pt -= 1;
        if (val == 1 || val >= 10)
            pt += 1;
        else if (type == 2)
            pt = 0;
    }
}
