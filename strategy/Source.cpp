#include <iostream>
using namespace std;


class RouteStrategy abstract
{
public:
	virtual void buildRoute() abstract;
};

class RoadStrategy :public RouteStrategy
{
public:
	void buildRoute() override
	{
		cout << "The route for roads has been built\n";
	}
};

class WalkingStrategy : public RouteStrategy
{
public:
	void buildRoute() override 
	{
		cout << "The route for hikers has been built\n";
	}
};
class PublicTransportStrategy : public RouteStrategy
{
public:
	void buildRoute() override
	{
		cout << "The route for public transport has been built\n";
	}
};

class Navigator
{
	RouteStrategy* routeStrategy;
public:
	void buildRoute()
	{
		routeStrategy->buildRoute();
	}
	void SetRouteStrategy(RouteStrategy* rSstrategy)
	{
		this->routeStrategy = rSstrategy;
	}
};




void main()
{
	Navigator navigator;
	RoadStrategy road_strategy;
	navigator.SetRouteStrategy(&road_strategy);
	navigator.buildRoute();

	WalkingStrategy walking_strategy;
	navigator.SetRouteStrategy(&walking_strategy);
	navigator.buildRoute();

	PublicTransportStrategy public_strategy;
	navigator.SetRouteStrategy(&public_strategy);
	navigator.buildRoute();
}