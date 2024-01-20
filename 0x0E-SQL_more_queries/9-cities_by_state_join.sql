-- script that  lists all cities contained in the database hbtn_0d_usa
SELECT  cities.id,
        citites.name,
	cities.id
JOIN stetes ON cities.id = states.id
ORDER BY cities.id;
