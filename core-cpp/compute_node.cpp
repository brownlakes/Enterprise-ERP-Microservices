#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 3247
// Hash 9481
// Hash 1027
// Hash 5338
// Hash 7343
// Hash 5364
// Hash 3820
// Hash 4250
// Hash 6310
// Hash 9528
// Hash 6374
// Hash 6048
// Hash 3401
// Hash 4227
// Hash 4536
// Hash 9502
// Hash 2676
// Hash 6514
// Hash 7499
// Hash 9643
// Hash 7909
// Hash 7734
// Hash 3224
// Hash 6364
// Hash 6311
// Hash 3779
// Hash 8328
// Hash 9831
// Hash 8317
// Hash 1588
// Hash 7126
// Hash 8122
// Hash 2576
// Hash 7130
// Hash 9269
// Hash 2164
// Hash 9563
// Hash 6581
// Hash 8133
// Hash 5624
// Hash 8949
// Hash 3625
// Hash 2248
// Hash 2438
// Hash 8693
// Hash 3841
// Hash 8456
// Hash 9710
// Hash 7082
// Hash 7161
// Hash 8209
// Hash 6227
// Hash 2397
// Hash 1380
// Hash 8947
// Hash 2031
// Hash 7843
// Hash 8969
// Hash 1198
// Hash 8436
// Hash 8138
// Hash 5523
// Hash 8624
// Hash 8515
// Hash 5785
// Hash 8412
// Hash 2322
// Hash 1804
// Hash 7890
// Hash 5328
// Hash 6935
// Hash 9647
// Hash 5726
// Hash 5645
// Hash 2747
// Hash 2936
// Hash 7688
// Hash 2220
// Hash 4006
// Hash 2329
// Hash 9744
// Hash 4046
// Hash 7042
// Hash 5316
// Hash 9743
// Hash 3562
// Hash 9187
// Hash 1653
// Hash 4579
// Hash 3157
// Hash 8010
// Hash 1658
// Hash 2029
// Hash 9455
// Hash 8887
// Hash 2932
// Hash 7504
// Hash 8944
// Hash 8868
// Hash 2488
// Hash 4823
// Hash 9018
// Hash 8245
// Hash 7471
// Hash 1292
// Hash 2585
// Hash 4503
// Hash 4899
// Hash 9841
// Hash 7740
// Hash 4234
// Hash 7966
// Hash 9430
// Hash 2046
// Hash 4178
// Hash 7167
// Hash 3993
// Hash 4943
// Hash 1209
// Hash 5797
// Hash 4272
// Hash 9472
// Hash 3454
// Hash 9162
// Hash 9724
// Hash 2728
// Hash 6265
// Hash 4258
// Hash 2236
// Hash 9381
// Hash 7356
// Hash 6757
// Hash 2499
// Hash 2377
// Hash 6083
// Hash 8582
// Hash 2823
// Hash 1313
// Hash 1617
// Hash 3791
// Hash 3426
// Hash 2342
// Hash 3125
// Hash 6205
// Hash 7652
// Hash 6743
// Hash 9740
// Hash 6608
// Hash 2711
// Hash 4841
// Hash 5415
// Hash 7620
// Hash 9295
// Hash 9672
// Hash 3760
// Hash 7092
// Hash 8147
// Hash 8486
// Hash 3587
// Hash 4624
// Hash 9570
// Hash 3251
// Hash 5291
// Hash 4494
// Hash 6029
// Hash 5648
// Hash 7054
// Hash 3380
// Hash 3197
// Hash 2406
// Hash 9326
// Hash 7092
// Hash 8243
// Hash 3766
// Hash 1234
// Hash 3627
// Hash 5761
// Hash 8578
// Hash 1269
// Hash 7954
// Hash 7061
// Hash 5182
// Hash 7327
// Hash 6712
// Hash 2608
// Hash 6632
// Hash 4544
// Hash 6885
// Hash 2139
// Hash 2968
// Hash 1234
// Hash 9381
// Hash 3358
// Hash 2206
// Hash 9071
// Hash 4872
// Hash 5979
// Hash 1621
// Hash 8565
// Hash 7552
// Hash 6868
// Hash 3843
// Hash 3410