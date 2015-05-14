<?php

/**
 * Callback function to alter text widget.
 * @param  array $element Element to be altered
 */
function srf_text_alter_widget(&$element) {
  $element['value']['#title'] = theme('srf_field_label', array(
    'title' => $element['value']['#title'],
  ));
}

/**
 * Callback function to alter text_long widget.
 * @param  array $element Element to be altered
 */
function srf_text_long_alter_widget(&$element) {
  $element['value']['#title'] = theme('srf_field_label', array(
    'title' => $element['value']['#title'],
  ));
}

/**
 * Callback function to alter text_with_summary widget.
 * @param  array $element Element to be altered
 */
function srf_text_with_summary_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
}

/**
 * Callback function to alter entityreference widget.
 * @param  array $element Element to be altered
 */
function srf_entityreference_alter_widget(&$element) {
  $element['target_id']['#title'] = theme('srf_field_label', array(
    'title' => $element['target_id']['#title'],
  ));
}

/**
 * Callback function to alter taxonomy_term_reference widget.
 * @param  array $element Element to be altered
 */
function srf_taxonomy_term_reference_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
}

/**
 * Callback function to alter file or image widget.
 * @param  array $element Element to be altered
 */
function srf_file_alter_widget(&$element) {
  if (isset($element['#title'])) {
    $element['#title'] = theme('srf_field_label', array(
      'title' => $element['#title'],
    ));
  }
  else {
    foreach ($element as $id => &$elem) {
      if (isset($elem['#title'])) {
        $elem['#title'] = theme('srf_field_label', array(
          'title' => $elem['#title'],
        ));
      }
    }
  }
}

/**
 * Callback function to alter date* widget.
 * @param  array $element Element to be altered
 */
function srf_date_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
}

/**
 * Callback function to alter link_field widget.
 * @param  array $element Element to be altered
 */
function srf_link_field_alter_widget(&$element) {
  dpm($element, "element");
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
}

/**
 * Callback function to alter email widget.
 * @param  array $element Element to be altered
 */
function srf_email_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
  $element['email']['#title'] = theme('srf_field_label', array(
    'title' => $element['email']['#title'],
  ));
}
