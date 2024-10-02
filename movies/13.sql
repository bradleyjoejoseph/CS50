select distinct(name) from people
inner join stars on people.id=stars.person_id
inner join movies on stars.movie_id=movies.id
where movies.title in(select distinct(movies.title) from people
inner join stars on people.id=stars.person_id
inner join movies on stars.movie_id=movies.id
where people.name = "Kevin Bacon" and birth = 1958)
and people.name != "Kevin Bacon"
;