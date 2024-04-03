-- script that  lists all cities contained in the database hbtn_0d_usa
SELECT  cities.id,
        citites.name,
	cities.name
FROM cities
JOIN stetes ON cities.state_id = states.id
ORDER BY cities.id;
