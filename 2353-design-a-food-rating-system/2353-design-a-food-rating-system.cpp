class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisines_ratings;
    unordered_map<string, string> foods_cuisines;
    unordered_map<string, int> foods_ratings;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            cuisines_ratings[cuisines[i]].insert({-ratings[i], foods[i]});
            foods_cuisines[foods[i]] = cuisines[i];
            foods_ratings[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisines = foods_cuisines[food];
        cuisines_ratings[cuisines].erase({-foods_ratings[food], food});
        cuisines_ratings[cuisines].insert({-newRating, food});
        foods_ratings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(cuisines_ratings[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */