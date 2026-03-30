class Twitter {
public:
    unordered_map<int, vector<int>> followersmap;
    unordered_map<int, vector<pair<int, int>>> tweetsmap;
    int tweetno = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsmap[userId].push_back({tweetId, tweetno});
        tweetno++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> followers = followersmap[userId];
        followers.push_back(userId);
        vector<int> news;
        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;  // min-heap based on timestamp
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> newsheap(cmp);

        for(int user : followers){
            // cout << "user : " << user << " tweets :" ;
            auto & tweets = tweetsmap[user];
            for(int i= tweets.size()-1; i>=0; i--){
                // cout << tweets[i].first << " ";
                newsheap.push(tweets[i]);
                if(newsheap.size() > 10){
                    cout << "size : " << newsheap.size() << endl;
                    cout << "top : " << newsheap.top().first << endl; 
                    newsheap.pop();
                    }
            }
        }

        while(!newsheap.empty()){
            auto &p = newsheap.top();
            // cout <<"top "<< p.first << " " ;
            news.push_back(p.first);
            newsheap.pop();
            // cout <<"bottom "<< p.first << " ";
            // for(int n: news) cout << n << " ";
            // cout << endl;
        }
        // cout << endl;
        reverse(news.begin(), news.end());

        // for(int user : followers){
        //     cout << "checking user : " << user << " tweets :" ;
        //     auto & tweets = tweetsmap[user];
        //     for(int i= tweets.size()-1; i>=0; i--){
        //         cout << tweets[i].first << " ";
        //     }
        //     cout << endl;
        // }
        return news;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            vector<int> already;
            if(followersmap.find(followerId) !=  followersmap.end()) already = followersmap[followerId];
            if(already.empty() || find(already.begin(), already.end(), followeeId) == already.end())
            {followersmap[followerId].push_back(followeeId);}
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        vector<int> followers = followersmap[followerId];
        vector<int> newfollowers;
        for(int user: followers){
            if(user!=followeeId) newfollowers.push_back(user);
        }
        followersmap[followerId] = newfollowers;
    }
};
