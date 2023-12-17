class Food{
    public:
    int foodRating;
    string foodName;
    Food(int foodRating,string foodName){
        this->foodRating=foodRating;
        this->foodName=foodName;
    }
    bool operator<(const Food& other  ) const{
        if(foodRating==other.foodRating){
            return foodName > other.foodName;
        }
        return foodRating< other.foodRating;
    }
};
class FoodRatings {
public:
    unordered_map<string,int> foodRatingMap;
    unordered_map<string,string> foodCuisinesMap;
    unordered_map<string,priority_queue<Food>> cuisineFoodMap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodRatingMap[foods[i]]=ratings[i];
            foodCuisinesMap[foods[i]]=cuisines[i];
            cuisineFoodMap[cuisines[i]].push(Food(ratings[i],foods[i]));
        }
        
    }
    
    void changeRating(string food, int newRating) {
        foodRatingMap[food]=newRating;
        auto cuisineName= foodCuisinesMap[food];
        cuisineFoodMap[cuisineName].push(Food(newRating,food));
    }
    
    string highestRated(string cuisine) {
        auto highestRated=cuisineFoodMap[cuisine].top();
        while(foodRatingMap[highestRated.foodName]!=highestRated.foodRating){
            cuisineFoodMap[cuisine].pop();
            highestRated=cuisineFoodMap[cuisine].top();
        }
        return highestRated.foodName;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */