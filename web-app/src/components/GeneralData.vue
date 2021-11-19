<template>

    <div class="container-fluid">
        <div class="row">
            <div class="col-md">
                <div class="card">
                    <div class="card-body">
                        <h5 class="card-title text-center">Informação do ambiente</h5>
                        <div class="card-group">
                            <div class="card">
                                <div class="card-body">
                                    <div>
                                        <div class="d-flex">
                                            <i class="fas fa-thermometer-half pe-1"></i>
                                            <strong> Temperature API </strong>
                                            <div id="currentTemp" class="ms-auto"></div>
                                        </div>
                                    </div>
                                    <div>
                                        <div class="d-flex">
                                            <i class="fas fa-temperature-high text-danger pe-1"></i>
                                            <strong> Temperature </strong>
                                            <div id="maxTemp" class="ms-auto"></div>
                                        </div>
                                    </div>
                                    <div>
                                        <div class="d-flex">
                                            <i class="fas fa-temperature-low text-primary pe-1"></i>
                                            <strong> Min. Temperature </strong>
                                            <div id="minTemp" class="ms-auto"></div>
                                        </div>
                                    </div>
                                    <div>
                                        <div class="d-flex">
                                            <i class="fas fa-percentage text-info pe-1"></i>
                                            <strong> Humidity </strong>
                                            <div id="humidity" class="ms-auto"></div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card">
                                <div class="card-body">
                                    <div>
                                        <div class="d-flex">
                                            <i class="fas fa-sun text-warning pe-1"></i>
                                            <strong> Sunrise Time </strong>
                                            <div id="sunriseTime" class="ms-auto"></div>
                                        </div>
                                    </div>
                                    <div>
                                        <div class="d-flex">
                                            <i class="far fa-sun text-warning pe-1"></i>
                                            <strong> Sunset Time </strong>
                                            <div id="sunsetTime" class="ms-auto"></div>
                                        </div>
                                    </div>
                                    <div>
                                        <div class="d-flex">
                                            <i class="fas fa-history text-sucess pe-1"></i>
                                            <strong> Fetched Time </strong>
                                            <div id="fetchedTime" class="ms-auto"></div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

</template>

<script>
export default {
  name: 'GeneralData',
}
</script>