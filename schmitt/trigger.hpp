#pragma once
namespace schmitt {

template<class T>
class trigger {
    public:
        trigger() = delete;
	    trigger(T low, T high, bool initial_state): _low(low), _high(high), _state(initial_state) {};
        ~trigger() {};
	    bool operator()(T read) { return _state = (read > _high) || (_state && !(read < _low)); };

    private:
	    T const _low{0}, _high{0};
	    bool _state{false};
};

template<class T>
class trigger_inverting {
    public:
        trigger_inverting() = delete;
	    trigger_inverting(T low, T high, bool initial_state): _low(low), _high(high), _state(initial_state) {};
        ~trigger_inverting() {};
	    bool operator()(T read) { return _state = (read < _low) || (_state && !(read > _high)); };

    private:
	    T _low{0}, _high{0};
	    bool _state{false};
};

} // namespace
